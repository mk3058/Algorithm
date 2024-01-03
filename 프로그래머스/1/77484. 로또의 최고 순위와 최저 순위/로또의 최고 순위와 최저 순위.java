class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int matchedNum=0;
        int ur_num=0;
        
        for(int x:lottos){
            if(x==0) ur_num++;
            else{
                for(int y:win_nums){
                    if(x==y){
                        matchedNum++;
                        break;
                    }
                }
            }
        }
        
        int tmp=matchedNum+ur_num;
        for(int i=0;i<2;i++){
            switch(tmp){
                case 6:
                    answer[i]=1;
                    break;
                case 5:
                    answer[i]=2;
                    break;
                case 4:
                    answer[i]=3;
                    break;
                case 3:
                    answer[i]=4;
                    break;
                case 2:
                    answer[i]=5;
                    break;
                default:
                    answer[i]=6;
                    break;
            }
            tmp-=ur_num;
        }
        
        return answer;
    }
}