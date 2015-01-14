//
//  main.c
//  Permutation
//
//  Created by Nicholas Arduini on 1/5/15.
//  Copyright (c) 2015 Nicholas Arduini. All rights reserved.
//

/*
 Today is Chef's birthday. His mom gifted him a truly lovable gift, a permutation of first N positive integers.
 She placed the permutation on a very long table in front of Chef and left it for him to play with it. But as there was a lot of people coming and wishing him. It was interfering with his game which made him very angry and he banged the table very hard due to which K numbers from the permutation fell down and went missing.
 Seeing her son's gift being spoilt, his mom became very sad. Chef didn't want his mom to be sad as he loves her the most. So to make her happy, he decided to play a game with her with the remaining N - K numbers on the table. Chef wants his mom to win all the games.
 Chef and his mom play alternatively and optimally. In Xth move, a player can choose some numbers out of all the numbers available on the table such that chosen numbers sum up to X. After the move, Chosen numbers are placed back on the table.The player who is not able to make a move loses.
 Now, Chef has to decide who should move first so that his Mom wins the game.
 As Chef is a small child, he needs your help to decide who should move first. Please help him, he has promised to share his birthday cake with you :)
 Input
 
 First Line of input contains a single integer T denoting the number of test cases.
 First line of each test case contains two space separated integers N and K denoting the size of
 permutation and number of numbers fall down from the table.
 Next line of each test case contains K space separated integers denoting the values of missing numbers.
 Output
 
 For each test case, print "Chef" if chef should move first otherwise print "Mom" (without quotes).
 Constraints
 
 1 ≤ T ≤ 105, 1 ≤ N ≤ 109
 0 ≤ K ≤ min(105, N)
 All K numbers are distinct.
 Value of each of K number belongs to [1,N].
 Sum of K over all the test cases does not exceed 5*105.
 Scoring
 
 Subtask 1 (13 pts): 1 ≤ T ≤ 100, 1 ≤ N ≤ 102, 1 ≤ K < N.
 Subtask 2 (17 pts): 1 ≤ T ≤ 100, 1 ≤ N ≤ 105, K = 0.
 Subtask 3 (70 pts): Original Constraints.
 Example
 
 Input
 2
 5 2
 3 5
 5 1
 1
 Output
 Mom
 Chef
 Explanation
 
 For test case 1.
 Mom can choose {1} to make 1.
 Chef can choose {2} to make 2.
 Mom can choose {1,2} to make 3.
 Chef can choose {4} to make 4.
 Mom can choose {1,4} to make 5.
 Chef can choose {2,4} to make 6.
 Mom can choose {1,2,4} to make 7.
 Chef cannot make 8 out of the numbers on the table.
 So,Chef loses and Mom wins.
*/

#include <stdio.h>
#include <stdlib.h>

int cmpFun (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main(void) {
    
    int cases, size, drops, num, i, j, k, n, index;
    
    scanf("%d", &cases);
    
    for (i = 0; i < cases; ++i) {
        
        int sum = 0, dropSum = 0;
        
        scanf("%d%d", &size, &drops);
        
        if (drops == 0) {
            index = size * (size + 1) / 2 + 1;
            if (index % 2)
                printf("Chef\n");
            else
                printf("Mom\n");
            continue;
        }
        
        int *arr = malloc(drops * sizeof(int));
        
        for (j = 0; j < drops; ++j) {
            scanf("%d", &num);
            arr[j] = num;
            dropSum += num;
        }
        
        qsort(arr, drops, sizeof(int), cmpFun);
        
        int earlyBreak = 0;
        
        for (n = 1, k = 0; n < size && sum < size; ++n) {
            if (n != arr[k]) {
                sum += n;
            }
            else {
                if (sum < arr[k]) {
                    earlyBreak = 1;
                    index = arr[k];
                    break;
                }
                ++k;
            }
        }
        if (!earlyBreak) {
            index = size * (size + 1) / 2 - dropSum + 1;
        }

        if (index % 2)
            printf("Chef\n");
        else
            printf("Mom\n");
        
        free(arr);
        
    }
    
    return 0;
}
