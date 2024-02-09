package com;

import java.util.*;
import java.text.*;


public class Practice{
    public static String makinStrings(){
        String s = "Fred";
        s = s + "47";
        s = s.substring(2, 5);
        s = s.toUpperCase();
        return s.toString();
    }

    public static void ques11() {
        String my_string = makinStrings();
        System.out.println("\nQues 11: " + my_string);
    }

    public static void ques10(String text) {
        int check = 4;
        if (check == text.length()){
            System.out.print(text.charAt(check -= 1) + ", ");
        }
        else{
            System.out.print(text.charAt(0) + ", ");
        }
    }

    public static void ques9() {
        String s1 = "abc";
        String s2 = new String("abc");

        System.out.print("Ques 9: ");
        if(s1 == s2)
            System.out.print(1);
        else
            System.out.print(2);


        if(s1.equals(s2))
            System.out.print(3);
        else
            System.out.print(4);
    }

    public static void ques8() {
        int i=0, j=2;
        do{
            i = ++i;
            j--;
        }while(j > 0);
        System.out.println("Ques 8: " + i);
    }

    public static void ques6() {
        boolean x = true;
        int a;

        if(x){
            a = x ? 1:2;
        }else{
            a = x ? 3:4;
        }
        System.out.println("Ques 6: " + a);
    }

    public static void ques5() {
        int i = 0;
        boolean t = true;
        boolean f = false;
        boolean b;
        b = (t | ((i++) == 0));
        b = (f | ((i+=2) > 0));
        System.out.println("\nQues 5: " + i);
    }

    public static void ques2() {
        String text  = "Betty bought some butter";
        String[] words = text.split(" ");

        System.out.print("Ques 2: ");
        for( String word : words ) {
            System.out.print(word+" ");
        }
    }

    public static void ques1() {
        SimpleDateFormat formatDate = new SimpleDateFormat("HH:mm:ss");
        Date date = new Date();
        formatDate.setTimeZone(TimeZone.getTimeZone("IST"));
 
        System.out.println("Ques 1: "+formatDate.format(date));
    }

    public static void main(String args[]) {
        ques1();
        ques2();
        ques5();
        ques6();
        ques8();
        ques9();
        System.out.print("\nQues 10: ");
        ques10("four");
        ques10("tee");
        ques10("to");
        ques11();
    }
}
