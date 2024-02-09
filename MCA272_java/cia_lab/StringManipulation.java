/**
 * StringManipulation
 */
public class StringManipulation {

        public static int countVowels(String str) {
            int vowelCount = 0;
            for (char c : str.toCharArray()) {
                if (isVowel(c)) {
                    vowelCount++;
                }
            }
            return vowelCount;
        }
    
        public static boolean isVowel(char c) {
            c = Character.toLowerCase(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
    
        public static String convertToUpperCase(String str) {
            return str.toUpperCase();
        }
    
        public static String reverseString(String str){
            StringBuffer sb = new StringBuffer();
            for (int i = str.length() - 1; i >= 0; i--) {
                sb.append(str.charAt(i));
            }
            return sb.toString();
        }
    
        public static void main(String[] args){
            String inputString = "This is a test string";
    
            int vowelCount = countVowels(inputString);
            System.out.println("Number of vowels: " + vowelCount);
    
            String uppercaseString = convertToUpperCase(inputString);
            System.out.println("Uppercase string: " + uppercaseString);
    
            String reversedString = reverseString(inputString);
            System.out.println("Reversed string: " + reversedString);
        }
}