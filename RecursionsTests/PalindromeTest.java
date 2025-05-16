package RecursionsTests;

public class PalindromeTest {
    public static void main(String[] args) {
        Sentence sentence = new Sentence("racecar");
        System.out.println("Is 'racecar' a palindrome? " + sentence.isPalindromeEfficient("racecar", 0, 6));

        
        Sentence sentence2 = new Sentence("hello");
        System.out.println("Is 'hello' a palindrome? " + sentence2.isPalindrome());
        
        Sentence sentence3 = new Sentence("a");
        System.out.println("Is 'a' a palindrome? " + sentence3.isPalindrome());
        
        Sentence sentence4 = new Sentence("aa");
        System.out.println("Is 'aa' a palindrome? " + sentence4.isPalindrome());
        Sentence sentence5 = new Sentence("Hi sir ris ih");
        System.out.println("Is 'Hi sir ris ih' a palindrome? " + sentence5.isPalindrome());
    }
}
