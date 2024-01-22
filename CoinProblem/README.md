# Coin Problem

Given `coins = {c_1,c_2,...,c_k}` and a target sum `n` we have to make sum equals n using as few coins as possible

### Recursive Formula

- `solve(x) = min(1 + min(x-c_j))`

### Memoization

- In DP we generally have a lot of overlapping subproblems and by recursion we are doing the call for already called value more than one time

- We can have a `vector<int> memo(target+1,-1)`:
```
if(memo[target]!=-1){
    return memo[target];
}
else{
    do the whole code ....
    .
    .
    memo[target]=ans; // next time we we gonna need it we will have it saved
}
```

### DP Iterative

- In this we develop this based on memo code here our solution is based on `target`
- So basically we make a array `vector<int> ans(target+1,-1)`
- Now we will go from solving for `target = 0 ` to `target`