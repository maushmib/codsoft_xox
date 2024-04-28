#include<iostream>
using namespace std;
void board(char b[3][3]){
    int i,j;
    cout<<"_____________"<<endl;
    for(i=0;i<3;i++){
        cout<<"| ";
        for(j=0;j<3;j++)
        {
        cout<<b[i][j]<<" | ";
        }
        cout<<endl<<"_____________"<<endl;
    }
}
int winorlose(char a[3][3],char player)
{
    int j;
        for(j=0;j<3;j++)
        {
         if((player==a[0][j])&&(player==a[1][j])&&(player==a[2][j]))
         return 1;
        
        else 
        if((player==a[j][0])&&(player==a[j][1])&&(player==a[j][2])){
            return 1;
        }
        }
       if(((player==a[0][0])&&(player==a[1][1])
        &&(player==a[2][2]))||((player==a[0][2])&&(player==a[1][1])&&(player==a[2][0]))){
        return 1;}
        
        
    return 0;
}

int main(){
    char b[3][3];
    int i,j;
    char player='x';
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
        {
           b[i][j]=' ';
        }
    }
    
    
    board(b);
    int r,c,moves=9;
    while((moves<10)&&(moves>0)){
        cout<<"enter row and column  :";
 
        cin>>r>>c;
        if((b[r][c]!=' ')||((r<0)||(r>2))||((c<0)||(c>2)))
        {
            cout<<"invalid move"<<endl;
            cout<<"try again with another row and column that lies between 0 and 2"<<endl;
            cin>>r>>c;
        }
        b[r][c]=player;
       
        if((winorlose(b,player))==1){
            cout<<"congratulations! player "<<player<<" wins the game"<<endl;
            return 1;
            
        }
        board(b);
        
       
        player=(player=='x')?'o':'x';
        moves--;
        
        if(moves==0&&winorlose(b,player)==false){
            cout<<"game draw!!";
        }
        
    }

    cout<<"final board:"<<endl;
    board(b);
    
    return 0;}