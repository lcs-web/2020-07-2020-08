给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

思路及算法
考虑前面的双指针的做法，我们注意到我们有大量的时间用于在 ttt 中找到下一个匹配字符。
这样我们可以预处理出对于 ttt 的每一个位置，从该位置开始往后每一个字符第一次出现的位置。
我们可以使用动态规划的方法实现预处理，令 f[i][j]f[i][j]f[i][j] 表示字符串 ttt 中从位置 iii 开始往后字符 jjj 第一次出现的位置。在进行状态转移时，如果 ttt 中位置 iii 的字符就是 jjj，那么 f[i][j]=if[i][j]=if[i][j]=i，否则 jjj 出现在位置 i+1i+1i+1 开始往后，即 f[i][j]=f[i+1][j]f[i][j]=f[i+1][j]f[i][j]=f[i+1][j]，因此我们要倒过来进行动态规划，从后往前枚举 iii。
这样我们可以写出状态转移方程：
f[i][j]={i,t[i]=jf[i+1][j],t[i]≠jf[i][j]=\begin{cases}
i, & t[i]=j\\
f[i+1][j], & t[i] \neq j
\end{cases}
f[i][j]={i,f[i+1][j],​t[i]=jt[i]​=j​
假定下标从 000 开始，那么 f[i][j]f[i][j]f[i][j] 中有 0≤i≤m−10 \leq i \leq m-10≤i≤m−1 ，对于边界状态 f[m−1][..]f[m-1][..]f[m−1][..]，我们置 f[m][..]f[m][..]f[m][..] 为 mmm，让 f[m−1][..]f[m-1][..]f[m−1][..] 正常进行转移。这样如果 f[i][j]=mf[i][j]=mf[i][j]=m，则表示从位置 iii 开始往后不存在字符 jjj。
这样，我们可以利用 fff 数组，每次 O(1)O(1)O(1) 地跳转到下一个位置，直到位置变为 mmm 或 sss 中的每一个字符都匹配成功。

bool isSubsequence(char* s, char* t) {
    int n = strlen(s), m = strlen(t);

    int f[m + 1][26];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < 26; i++) {
        f[m][i] = m;
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (t[i] == j + 'a')
                f[i][j] = i;
            else
                f[i][j] = f[i + 1][j];
        }
    }
    int add = 0;
    for (int i = 0; i < n; i++) {
        if (f[add][s[i] - 'a'] == m) {
            return false;
        }
        add = f[add][s[i] - 'a'] + 1;
    }
    return true;
}
