import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    static HashMap<Character, Double> simpleEntropy(String filepath) throws IOException {
        String read = Files.readString(Paths.get(filepath));
        read = read.replaceAll("(?m)\\s*[\\/][\\/].*", "").trim();
        read = read.replaceAll("(?m)^\\s*", "").trim();
        read = read.replaceAll("(?m).*System.out.*", "").trim();
        read = read.replaceAll("^(?:[\\t ]*(?:\\r?\\n|\\r))+", "").trim();
        PrintWriter printWriter = new PrintWriter("processed_text.txt");
        printWriter.print(read);
        printWriter.close();
        // подсчёт символов через hashmap
        HashMap<Character, Integer> hashMap = new HashMap<>();
        // подсчёт букв в строке hashmap<буква,кол-во>
        for (Character c : read.toCharArray()) {
            if (hashMap.containsKey(c)) {
                hashMap.put(c, hashMap.get(c) + 1);
            }
            else {
                hashMap.put(c, 1);
            }
        }
        // отображение кол-ва символов
        System.out.println("\nQuantity of every character:");
        hashMap.forEach((k, v) -> System.out.println("Key: " + k + " Value: " + v));
        // вычисление отношения символа на весь текст
        // обратная запись, теперь hashmap <буква, отношение>
        HashMap<Character, Double> ratio = new HashMap<>();
        for (Map.Entry<Character, Integer> entry : hashMap.entrySet()) { // вычисление отношения символа на весь текст
            ratio.put(entry.getKey(), (double) entry.getValue() / read.length());
        }
        return ratio;
    }

    static HashMap<String, Double> groupEntropy(String filepath) throws IOException {
        String read = Files.readString(Paths.get(filepath));
        read = read.replaceAll("(?m)\\s*[\\/][\\/].*", "").trim();
        read = read.replaceAll("^\\s*", "").trim();
        read = read.replaceAll("(?m)System.out.*", "").trim();
        // подсчёт пар через hashmap
        HashMap<String, Integer> hashMap = new HashMap<>();
        // подсчёт пар в строке hashmap<пара,кол-во>
        for (int i = 0; i < read.length() - 1; i++) {
            if (hashMap.containsKey(read.substring(i, i + 2))) {
                hashMap.put(read.substring(i, i + 2),
                        hashMap.get(read.substring(i, i + 2)) + 1);
            }
            else {
                hashMap.put(read.substring(i, i + 2), 1);
            }
        }
        // отображение кол-ва пар символов
        System.out.println("\nQuantity of every pair:");
        hashMap.forEach((k, v) -> System.out.println("Key: " + k + " Value: " + v));
        // вычисление отношения пар на все пары
        // обратная запись, теперь hashmap <пара, отношение к всем парам>
        HashMap<String, Double> ratio = new HashMap<>();
        // вычисление отношения символа на весь текст
        for (Map.Entry<String, Integer> entry : hashMap.entrySet()) {
            ratio.put(entry.getKey(), (double) entry.getValue() / read.length());
        }
        return ratio;
    }

    static void process(String filename) throws IOException {
        HashMap<Character, Double> hashMap = simpleEntropy(filename);
        HashMap<String, Double> hashMapPairs = groupEntropy(filename);
/*        System.out.println("\nRatio:");
        hashMap.forEach((k, v) -> System.out.println("Key: " + k + " Value: " + v));*/
        calculateEntropy(hashMap.values(), 1);
/*        System.out.println("\nRatio:");
        hashMapPairs.forEach((k, v) -> System.out.println("Key: " + k + " Value: " + v));*/
        calculateEntropy(hashMapPairs.values(), 2);
    }

    static void calculateEntropy(Collection<Double> values, int divider) {
        Double result = 0.0;
        for (Double temp : values) {
            result += temp * (Math.log(temp) / Math.log(2));
        }
        result *= -1.0;
        result /= divider;
        System.out.println("Shannon entropy = " + result + "\n____________________________________________");
    }

    public static void main(String[] args) throws IOException {
        process("src\\main\\java\\Main.java");
    }
}
