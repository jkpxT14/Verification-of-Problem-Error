#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll=long long;

vector<int> A, B;
vector<vector<int>> A_Collection, B_Collection;
bool A_Check[9], B_Check[8];

void init()
{
    for(int i=0; i<=8; i++){
        A_Check[i]=true;
    }
    for(int i=0; i<=7; i++){
        B_Check[i]=true;
    }
}

void A_Selection(int idx)
{
    if(A.size()==8){
        A_Collection.push_back(A);
        return;
    }
    else if(idx>20){
        return;
    }
    else{
        if(A_Check[idx%9]){
            if(idx%9==0){
                A.push_back(idx);
                A_Check[0]=false;
                A_Selection(idx+1);
                A.pop_back();
                A_Check[0]=true;
                A_Selection(idx+1);
            }
            else{
                if(A_Check[9-idx%9]){
                    A.push_back(idx);
                    A_Check[9-idx%9]=false;
                    A_Selection(idx+1);
                    A.pop_back();
                    A_Check[9-idx%9]=true;
                    A_Selection(idx+1);
                }
                else{
                    A.push_back(idx);
                    A_Selection(idx+1);
                    A.pop_back();
                    A_Selection(idx+1);
                }
            }
        }
        else{
            A_Selection(idx+1);
        }
    }
}

void B_Selection(int idx)
{
    if(B.size()==8){
        B_Collection.push_back(B);
        return;
    }
    else if(idx>20){
        return;
    }
    else{
        if(B_Check[idx%8]){
            if(idx%8==0){
                B.push_back(idx);
                B_Check[0]=false;
                B_Selection(idx+1);
                B.pop_back();
                B_Check[0]=true;
                B_Selection(idx+1);
            }
            else{
                if(B_Check[8-idx%8]){
                    B.push_back(idx);
                    B_Check[8-idx%8]=false;
                    B_Selection(idx+1);
                    B.pop_back();
                    B_Check[8-idx%8]=true;
                    B_Selection(idx+1);
                }
                else{
                    B.push_back(idx);
                    B_Selection(idx+1);
                    B.pop_back();
                    B_Selection(idx+1);
                }
            }
        }
        else{
            B_Selection(idx+1);
        }
    }
}

void Ans_Cal()
{
    int cnt=0, sum_A=0, sum_B=0, ans=-1, ans_A_idx=-1, ans_B_idx=-1;
    bool intersection_check[21];
    for(int i=1; i<=20; i++){
        intersection_check[i]=false;
    }
    for(int i=0; i<A_Collection.size(); i++){
        for(int j=0; j<=7; j++){
            intersection_check[A_Collection[i][j]]=true;
            sum_A+=A_Collection[i][j];
        }
        for(int j=0; j<B_Collection.size(); j++){
            for(int k=0; k<=7; k++){
                if(intersection_check[B_Collection[j][k]]){
                    cnt++;
                }
                sum_B+=B_Collection[j][k];
            }
            if(cnt==1){
                if(ans<sum_A-sum_B){
                    ans=sum_A-sum_B;
                    ans_A_idx=i;
                    ans_B_idx=j;
                }
            }
            cnt=0;
            sum_B=0;
        }
        for(int j=1; j<=20; j++){
            intersection_check[j]=false;
        }
        sum_A=0;
    }
    cout<<ans<<"\n";
    for(int i=0; i<=7; i++){
        cout<<A_Collection[ans_A_idx][i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<=7; i++){
        cout<<B_Collection[ans_B_idx][i]<<" ";
    }
}

int main()
{
    init();
    A_Selection(1);
    B_Selection(1);
    // for(int i=0; i<A_Collection.size(); i++){
    //     for(int j=0; j<A_Collection[i].size(); j++){
    //         cout<<A_Collection[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0; i<B_Collection.size(); i++){
    //     for(int j=0; j<B_Collection[i].size(); j++){
    //         cout<<B_Collection[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<A_Collection.size()<<" "<<B_Collection.size()<<"\n";

    Ans_Cal();
}