#include<stdio.h> 
//#include<conio.h> 
int a[10][10],q[10],visit[10],n,i,j; 
void bfs(int v)
 {
      static int f=0,r=-1; 
      for(i=0;i<n;i++)
       if(a[v][i]==1 && visit[i]==0)
        q[++r]=i; 
       if(f<=r)
        {
             visit[q[f]]=1; 
             bfs(q[f++]); 
        } 
} 
void dfs(int u)
 {
      int i; 
      visit[u]=1; 
      for(i=0;i<n;i++)
       if(a[u][i]==1 && visit[i]==0)
        dfs(i); 
  } 
void main()
 {
      int v,f=1; 
      //clrscr(); 
      printf("Enter the number of nodes\n"); 
      scanf("%d",&n); 
      printf("Enter the adjacency matrix\n"); 
      for(i=0;i<n;i++)
       for(j=0;j<n;j++)
        scanf("%d",&a[i][j]); 
        for(i=0;i<n;i++)
         visit[i]=0; 
         printf("Enter the starting vertex\n"); 
         scanf("%d",&v);
         visit[v]=1; 
         bfs(v);// This function is for finding the reachable nodes from the given starting vertex
         printf("Nodes reachable from vertex %d:\n",v); 
         for(i=0;i<n;i++) 
          if(visit[i]==1 && i!=v)
           printf("%d\n",i); 
           for(i=0;i<n;i++)
            visit[i]=0;
          dfs(0);
          for(i=0;i<n;i++)
           if(visit[i]==0) 
           {
                f=0;
                break; 
           }
          if(f==0) 
           printf("The given graph is not connected");
          else
           printf("The given graph is connected"); 
           //getch(); 
}
