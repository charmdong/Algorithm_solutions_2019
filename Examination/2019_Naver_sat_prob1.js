function solution(emailList) {
    const reg = /^[a-z\.]+@[a-z]+.(com|net|org)$/;

    let result = emailList.filter(email => {
        if (email.match(reg)) {
            return email;
        }
    });

    return result.length;
}