package RecursionsTests;


public class Sentence {
    private String sentence;

    public Sentence(String sentence) {
        this.sentence = sentence.replace(" ", "").toLowerCase();
    }
    
    public boolean isPalindrome() {
        Character first = sentence.charAt(0);
        Character last = sentence.charAt(sentence.length() - 1);
        if (first == last) {
            if (sentence.length() == 1 | sentence.length() == 2) {
                return true;
            } else {
                String smallerSentence = sentence.substring(1, sentence.length() - 1);
                Sentence smaller = new Sentence(smallerSentence);
                return smaller.isPalindrome();
            }
        }
        return false;
    }

    public boolean isPalindromeEfficient(String sentence, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (sentence.charAt(start) != sentence.charAt(end)) {
            return false;
        }
        return isPalindromeEfficient(sentence, start + 1, end - 1);

    }

    public boolean isPalindromeIterative(String sentence) {
        int start = 0;
        int end = sentence.length() - 1;

        while (start < end) {
            if (sentence.charAt(start) != sentence.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
}

