public class NanoStringOps {
    public static void line(char ch, int n){
        for(int i=0; i<n; i++){
            System.out.print(ch);
        }
            System.out.println();
        
    }
    public static void performStringOps(String str) {

        // retrieve character at index.
        System.out.println("Char at 0: "+str.charAt(0)); 
        line('-', 8);
        // Do compasion check
        System.out.println("Comparison result: " + str.compareTo("I remember seeing a family of 4"));
        line('-', 8);


        // Using concat() to concatenate two strings
        System.out.println("Concatenated string: " + str.concat(" This is additional content."));
        line('-', 8);


        // Using contains() to check if a specific substring is present
        System.out.println("Does the str contain 'Tata Nano'? " + str.contains("Tata Nano"));

        //ends with
        System.out.println("Does the paragraph end with 'Rs 1 lakh.'? " + str.endsWith("Rs 1 lakh."));

        // equals -> checks the two paragraphs
        String anotherParagraph = "We realize that while our workers were thriving";
        System.out.println("Equal Paragraphs? " + str.equals(anotherParagraph));

        // Using equalsIgnoreCase() to check if two strings are equal ignoring case
        System.out.println("Paras equal?(Ignore case): " + str.equalsIgnoreCase("WE REALIZE that while our workers were thriving"));

        line('-', 8);

        // Format paragraph, pass the no of sentences
        System.out.println(String.format("The paragraph contains %d sentences.", 5));

        System.out.println("Substring: " + str.substring(20, 40));
        line('-', 8);


        // Using replace() to replace a specific substring
        System.out.println("Replaced String: " + str.replace("thriving", "prospering"));

        line('-', 8);

        // Using replaceAll() to replace based on a regular expression
        System.out.println("Regex Replaced String: " + str.replaceAll("\\b(\\w{4})\\b", "****"));

        // Using split() to split the string into an array
        String[] wordsArray = str.split("\\s+");
        System.out.println("Word Count: " + wordsArray.length);        
    }
    public static void main(String[] args) {
        String text = """
            We realizes that while our workers were thriving, the
            surrounding villages were still suffering. It became our goal to uplift their
            quality of life as well. I remember seeing a family of 4 on a motorbike in the
            heavy Bombay rain — I knew I wanted to do more for these families who were
            risking their lives for lack of an alternative” The alternative mentioned here
            is the Tata Nano, which soon after came as the world’s cheapest car on retail
            at a starting price of only Rs 1 lakh. These were the words of Ratan Tata in a
            recent post by Humans of Bombay which formed the basis of his decision to come
            up with a car like Tata Nano.
            """;
        performStringOps(text);
    }
}
