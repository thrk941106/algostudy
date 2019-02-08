#include<iostream>
#include<algorithm>

using namespace std;
int gear[5][9];
int K;
void turnCounterClockwise(int gear_num){
    int temp;
    temp = gear[gear_num][1];
    for(int i = 1 ; i<8 ; i++){
        gear[gear_num][i] = gear[gear_num][i+1];
    }
    gear[gear_num][8] = temp;
}
void turnClockwise(int gear_num){
    int temp;
    temp = gear[gear_num][8];
    for(int i = 8 ; i>1 ; i--){
        gear[gear_num][i] = gear[gear_num][i-1];
    }
    gear[gear_num][1] = temp;
}
int main(){
    
    for(int i=1 ; i<=4 ; i++){
        for(int j=1 ; j<=8 ; j++){
            scanf("%1d",&gear[i][j]);
        }
    }
    scanf("%d",&K);
    while(K--){
        int gear_num;
        int rotate_dir;
        int temp_dir;
        scanf("%d %d",&gear_num,&rotate_dir);
        if(rotate_dir == 1){
            turnClockwise(gear_num);
        }else{
            turnCounterClockwise(gear_num);
        }
        rotate_dir *= -1;
        temp_dir = rotate_dir;
        for(int i = gear_num+1 ; i<=4 ; i++){
                    if(rotate_dir == -1){
                        if(gear[i][7]!=gear[i-1][4]){
                        	turnCounterClockwise(i);
                            
                            rotate_dir *= -1;
                        } else{
                            break;
                        }
                    }else{
                        if(gear[i][7]!=gear[i-1][2]){
                            turnClockwise(i);
                            rotate_dir *= -1;
                        } else{
                            break;
                        }
                    }
         }
        rotate_dir = temp_dir;
         for(int i = gear_num-1 ; i>=1 ; i--){
                    if(rotate_dir == -1){
                        if(gear[i][3]!=gear[i+1][8]){
                            turnCounterClockwise(i);
                            rotate_dir *= -1;
                        } else{
                            break;
                        }
                    }else{
                        if(gear[i][3]!=gear[i+1][6]){
                            turnClockwise(i);
                            rotate_dir *= -1;
                        } else{
                            break;
                        }
                    }
         }

    }             
    int ans;
    ans = gear[1][1] + gear[2][1] * 2 + gear[3][1]*4 + gear[4][1]*8;
	printf("%d",ans);

}