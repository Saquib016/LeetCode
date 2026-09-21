class Solution {
    public boolean isValid(String s) {
        Deque<Character> Stack = new ArrayDeque<>();
        for(char c : s.toCharArray()){
           if(c=='('||c=='{'||c=='[') {
            Stack.push(c);
           }
           else{
                if(Stack.isEmpty()) return false;
                char top = Stack.peek();
                Stack.pop();
                if(c == ')' && top != '(') return false;
                if(c == ']' && top != '[') return false;
                if(c == '}' && top != '{') return false;
           }
        }
        return Stack.isEmpty();
    }
}