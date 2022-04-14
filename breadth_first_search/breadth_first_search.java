import java.util.HashSet;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Question4_BFS{

	public static void main(String a[])
	{
		//Test your program with the following example. 
		
		Node A = new Node ("A", null);
		Node B = new Node ("B", null);
		Node C = new Node ("C", null);
		Node D = new Node ("D", null);
		Node E = new Node ("E", null);
		Node F = new Node ("F", null);
		Node G = new Node ("G", null);
		Node H = new Node ("H", null);
		
		
		
		A.adjList = new Node[] {B,C};
		B.adjList = new Node[] {A};
		C.adjList = new Node[] {A,D};
		D.adjList = new Node[] {E,F};
		E.adjList = new Node[] {D};
		F.adjList = new Node[] {D,G};
		G.adjList = new Node[] {F};
		H.adjList = new Node[] {};
		
		System.out.println(Node.shortestPath(B, G));
		
	}
}

class Node //Node class
{
	String nodeName;   //attribute to label nodes
	Node [] adjList; //attribute to store adjacent nodes
	
	public Node (String nodeName, Node[] adjList) //Constructor
	{
		this.nodeName = nodeName;
		this.adjList = adjList;
	}
	
	public static String shortestPath (Node start, Node end)
	{
                HashSet<Node> v = new HashSet<>(); //Creating hashset for visited node
                HashMap<Node,Node> rPath = new HashMap<>(); 
                Node c;                            //Current
                Queue<Node> q = new LinkedList<>();
                q.add(start);
                v.add(start);
                boolean b = true;

                while(!q.isEmpty()){
                    c = q.remove();
                    if(c.nodeName.equals(end.nodeName)){
                        b = false;
                        break;
                    }
                    for(Node n:c.adjList){
                        if(!v.contains(n)){
                            v.add(n);
                            rPath.put(c, n);
                            q.add(n);
                        }
                    }
                }
                if(b) //When we cannot reach the node. So, in case b=true 
                    return "Node "+start.nodeName+"is not reachable"+end.nodeName+".";
                
                //Writing to string
                c = start;
                String string = c.nodeName;
                while(!c.nodeName.equals(end.nodeName)){
                    c = rPath.get(c);
                    string = string+"-->"+c.nodeName;
                }
		return string;
	}
}