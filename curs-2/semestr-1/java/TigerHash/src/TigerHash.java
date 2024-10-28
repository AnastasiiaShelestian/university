import java.util.Arrays;

public class TigerHash {

    // Векторы инициализации
    private static final byte[][] IV = {
            {(byte) 0xAA, (byte) 0xBB, (byte) 0xCC, (byte) 0xDD, (byte) 0xEE, (byte) 0xFF, 0x11, 0x22},
            {0x33, 0x44, 0x55, 0x66, 0x77, (byte) 0x88, (byte) 0x99, (byte) 0xAA},
            {(byte) 0xBB, (byte) 0xCC, (byte) 0xDD, (byte) 0xEE, (byte) 0xFF, (byte) 0xAA, (byte) 0xBB, (byte) 0xCC}
    };

    private static final int[] S_BLOCK = {
            0xD4, 0x6A, 0xE5, 0xBD, 0xE5, 0xD4, 0xC3, 0xE3, 0xB1, 0xA0
    };

    public static void main(String[] args) {
        String input = "Shelestian";

        // Преобразуем строку в байты
        byte[] bytes = input.getBytes();
        System.out.println("Исходные байты: " + Arrays.toString(bytes));

        // Применение S-блоков
        byte[] sBoxResult = applySBlocks(bytes);
        System.out.println("После S-блоков: " + toHexString(sBoxResult));

        // Применение перестановок
        byte[] permuted = applyPermutation(sBoxResult);
        System.out.println("После перестановок: " + toHexString(permuted));

        // Применение побитовых сдвигов
        byte[] shifted = applyBitShifts(permuted);
        System.out.println("После сдвигов: " + toHexString(shifted));

        // Операция XOR с IV
        byte[][] xorResult = applyByteWiseXOR(shifted);
        for (int i = 0; i < xorResult.length; i++) {
            System.out.println("После XOR с IV" + (i + 1) + ": " + toHexString(xorResult[i]));
        }
    }

    private static byte[] applySBlocks(byte[] input) {
        byte[] result = new byte[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = (byte) S_BLOCK[i];  // Применяем заранее определенные замены (для демонстрации)
        }
        return result;
    }

    private static byte[] applyPermutation(byte[] input) {
        byte[] result = new byte[input.length];
        result[0] = input[2];
        result[1] = input[4];
        result[2] = input[6];
        result[3] = input[0];
        result[4] = input[7];
        result[5] = input[5];
        result[6] = input[1];
        result[7] = input[3];
        result[8] = input[8];
        result[9] = input[9];
        return result;
    }

    private static byte[] applyBitShifts(byte[] input) {
        byte[] result = new byte[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = (byte) ((input[i] & 0xFF) << 2);
        }
        return result;
    }

    private static byte[][] applyByteWiseXOR(byte[] input) {
        byte[][] xorResult = new byte[3][input.length];
        for (int j = 0; j < IV.length; j++) {
            for (int i = 0; i < input.length; i++) {
                xorResult[j][i] = (byte) (input[i] ^ IV[j][i % IV[j].length]);
            }
        }
        return xorResult;
    }

    private static String toHexString(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02X ", b));
        }
        return sb.toString().trim();
    }
}
