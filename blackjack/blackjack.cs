using System;
using System.Collections.Generic;

//Semih KARACAOĞLU
//17050111008
//CENG 303 
//Problem Set 5 Blackjack Game

namespace bj{

	public class BlackJackPlay{

		public static int n = 52;
		public static int[] Deck = new int[52];

		public static int score(List<int> list){

			int total_amount = 0, current;
			for (int i = 0; i < list.Count; i++){ 
				current = list[i]; 
				int cVal = current % 13 + 1;
				if (cVal == 1)
				{
					if (total_amount + cVal > 21){
						cVal = 1;
					}
					else{
						cVal = 11;
					}
				}
				if (cVal >= 10){
					cVal = 10;
				}
				total_amount += cVal;
			}
			return total_amount;
		}

		public static int BJ(int i){
			List<int> options = new List<int>();
			int pScore = 0, dScore = 0;

			if (n - i < 4){
				return 0;
			}

			for (int p = 2; p < n - i - 1; p++){
				List<int> pScoreArr = new List<int>();

				pScoreArr.Add(Deck[i]);
				pScoreArr.Add(Deck[i + 2]);

				for (int c = i + 4; c < i + p + 2; c++){
					pScoreArr.Add(Deck[c]);
				}
				pScore = score(pScoreArr);
				if (pScore > 21){
					options.Add(-1 + BJ(i + p + 2));
					break;
				}
				int d;
				for (d = 2; d < n - i - p; d++){
					List<int> dScoreArr = new List<int>();
					dScoreArr.Add(Deck[i + 1]);
					dScoreArr.Add(Deck[i + 3]);

					for (int de = i + p + 2; de < i + p + d; de++){
						dScoreArr.Add(Deck[de]);
					}
					dScore = score(dScoreArr);
					if (dScore >= 17){
						break;
					}
				}
				if (dScore > 21){
					dScore = 0;
				}
				options.Add(pScore.CompareTo(dScore) + BJ(i + p + d));
			}
			options.Sort();
			int maxValue = options[options.Count - 1];

			return maxValue;
		}

		public static void Main(string[] args){

			Console.WriteLine("\t\t\t\t\t*******************************");
			Console.WriteLine("\t\t\t\t\t***Welcome To Blackjack Game***");
			Console.WriteLine("\t\t\t\t\t*******************************\n\n");
			Console.WriteLine("Please write your deck integers with commas (For example: 3,6,4,8,15,34,23,...). Don't use blanks between numbers.\n");
			string str = Console.ReadLine();
			char[] cDividers = { ',', ' ' };
			string[] deckStr = str.Split(cDividers);

			for (int j = 0; j < deckStr.Length; j++){

				Deck[j] = int.Parse(deckStr[j]);
			}
			int Credit = BJ(0);
			Console.WriteLine("\nThe maximum amount of money you can earn is: " + Credit);
			Console.WriteLine("It was a great game. See you later...");
		}
	}
}
