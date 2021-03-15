import java.math.BigInteger;
import java.util.HashMap;

public class Codec {
    String header = "http://tinyurl.com/";
    static BigInteger num = new BigInteger("0");
    String t = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    HashMap<String, String> decoding = new HashMap<>();
    HashMap<String, String> encoding = new HashMap<>();

    public String num_to_62system(BigInteger num) {
        BigInteger temp[] = num.divideAndRemainder(BigInteger.valueOf(62));
        if (temp[0].intValue() == 0) {
            return Character.toString(t.charAt(temp[1].intValue()));
        } else {
            return num_to_62system(temp[0]) + Character.toString(t.charAt(temp[1].intValue()));
        }
    }

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if (encoding.containsKey(longUrl)) {
            return encoding.get(longUrl);
        }else {
            String key = String.format("%6s", num_to_62system(num)).replace(' ', '0');
            encoding.put(longUrl, key);
            decoding.put(key, longUrl);
            num = num.add(BigInteger.valueOf(1));
            return header + key;
        }
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        String key = shortUrl.split(header)[1];
        return decoding.get(key);
    }

}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));