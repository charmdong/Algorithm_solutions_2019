function solution(words, queries) {
    var answer = [];

    queries.forEach(query => {
        let keyWord = "";
        const queryLen = query.length;
        const isTail = (query[0] != '?');

        for(var index = 0; index < queryLen; index++) {
            if(query[index] != '?') {
                keyWord += query[index];
            }
        }

        let count = 0;
        words.sort();
        words.forEach(word => {
            if(word.length === queryLen) {
                let subStr;
                
                if(isTail) {
                    subStr = word.substr(0, keyWord.length);
                } else {
                    subStr = word.substr(queryLen - keyWord.length);
                }

                if(subStr > keyWord){
                    return;
                }
                
                if(subStr === keyWord) {
                    count++;
                }
            }
        });

        answer.push(count);
    });

    return answer;
}

const res = solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?", "???nt"]);
console.log(res);