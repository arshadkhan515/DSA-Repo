// elimination game leetcode question
// https://leetcode.com/problems/elimination-game/
// In this question we have to find the last remaining element in the array after the elimination process is done
// https://www.thecodehelp.in/s/courses/62d687250cf20fa2aeac4205/take  first question


// code:
int lastRemaining(int n) {
        if(n == 1) return n;

        return 2 * (1 + n/2 - lastRemaining(n/2));
}