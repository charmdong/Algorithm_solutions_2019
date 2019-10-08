function solution(sticker) {
    const sLen = sticker.length;
    let dp = Array(sLen + 1).fill(0);
    
    if(sLen <= 2) {
        if(sLen == 1){
            return sticker[0];
        }
        return Math.max(sticker[0], sticker[1]);
    }

    dp[0] = 0;
    dp[1] = sticker[0];
    dp[2] = sticker[1];

    for(var index = 3; index <= sLen; index++) {
        dp[index] = Math.max(dp[index - 1], dp[index - 2] + sticker[index - 1]);
    }
    
    return dp[sLen];
}