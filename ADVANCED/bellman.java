import java.util.Scanner;


public class bellman {
    public static void main(String[] args) {
    int v, sv;
    int dist[]=new int[50];
    int w[][]=new int[50][50];
    int path[]=new int[50];
    Scanner in=new Scanner(System.in);
    System.out.println("Enter the number of vertices");
    v=in.nextInt();
    System.out.println("Enter the weight of matrix");
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            w[i][j]=in.nextInt();
    }
}
System.out.println("Enter weight matix is");
for(int i=1;i<=v;i++){
    for(int j=1;j<=v;j++){
        System.out.println(w[i][j]+"\t");
        }
        System.out.println();
}
System.out.println("Enter the source verices");
sv=in.nextInt();
bellman(v,sv,dist,w,path);
printpath(v,sv,dist,path);
    }
static void bellman(int v,int sv,int dist[],int w[][],int path[]){
    for(int i=1;i<=v;i++){
        dist[i]=999;
}
dist[sv]=0;
for(int src=1;src<=v;src++){
    for(int dest=1;dest<=v;dest++){
        if(dist[dest]>(dist[src]+w[src][dest])){
           dist[dest]=dist[src]+w[src][dest];
           path[dest]=src;
        }
    }
}
for(int src=1;src<=v;src++){
    for(int dest=1;dest<=v;dest++){
        if(dist[dest]>(dist[src]+w[src][dest])){
            System.out.println("The graph contains negative cycle");
            System.exit(0);
        }
    }
}
}

static void printpath(int v, int sv,int dist[],int path[]){
    for(int i=1;i<=v;i++){  
        System.out.println("The Shortedt distance from"+sv+"-->"+i+"is"+dist[i]);
        if(dist[i]<0){
            System.out.println("The graph contains negative weight Edge");
        }
        if(i!=sv){
            int t= path[i];
            System.out.print("The path is"+i);
            while(t!=sv){
                System.out.println("<-->"+t);
                t=path[t];
            }    
            System.out.println("<-->"+sv);    
        }
        System.out.println();
}
}
}





