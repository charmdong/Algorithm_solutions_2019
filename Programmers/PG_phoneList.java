class PG_phoneList {
    public boolean solution(String[] phone_book) {
        boolean answer = true;

        for(int index = 0; index < phone_book.length; index++) {
            for(int next = 0; next < phone_book.length; next++) {
                if(index != next && (phone_book[next].startsWith(phone_book[index]))) {
                    return false;
                }
            }
        }

        return answer;
    }
}