import java.io.IOException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.spec.AlgorithmParameterSpec;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class DesProgram {

    // creating an instance of the Cipher class for encryption
    private static Cipher encrypt;

    // creating an instance of the Cipher class for decryption
    private static Cipher decrypt;

    // initializing vector
    private static final byte[] initialization_vector = { 22, 33, 11, 44, 55, 99, 66, 77 };

    // main() method
    public static void main(String[] args) {
        // path of the file that we want to encrypt
        String plaintext = "This is a test message for encryption and decryption";

        try {
            // generating keys using the SecretKey class
            SecretKey secretKey = KeyGenerator.getInstance("DES").generateKey();
            AlgorithmParameterSpec aps = new IvParameterSpec(initialization_vector);

            // setting encryption mode
            encrypt = Cipher.getInstance("DES/CBC/PKCS5Padding");
            encrypt.init(Cipher.ENCRYPT_MODE, secretKey, aps);

            // setting decryption mode
            decrypt = Cipher.getInstance("DES/CBC/PKCS5Padding");
            decrypt.init(Cipher.DECRYPT_MODE, secretKey, aps);

            // calling encrypt() method to encrypt the plaintext
            byte[] encryptedText = encryption(plaintext);

            // calling decrypt() method to decrypt the encrypted text
            String decryptedText = decryption(encryptedText);

            // prints the encrypted and decrypted messages
            System.out.println("Original Message: " + plaintext);
            System.out.println("Encrypted Message: " + new String(encryptedText, "UTF-8"));
            System.out.println("Decrypted Message: " + decryptedText);

        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException
                | InvalidAlgorithmParameterException | IOException | BadPaddingException |
                IllegalBlockSizeException e) {
            e.printStackTrace();
        }
    }

    // method for encryption
    private static byte[] encryption(String inputText) throws BadPaddingException,
            IllegalBlockSizeException {
        return encrypt.doFinal(inputText.getBytes());
    }

    // method for decryption
    private static String decryption(byte[] encryptedText) throws BadPaddingException,
            IllegalBlockSizeException {
        byte[] decryptedBytes = decrypt.doFinal(encryptedText);
        return new String(decryptedBytes);
    }
}
