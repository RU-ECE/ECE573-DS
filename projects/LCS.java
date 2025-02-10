public class LCS {
    public static int LCS(String X, String Y) {
        // if no letters match, return 0
        if (X.length() == 0 || Y.length() == 0) {
            return 0;

        // if the first letters match, return 1 + LCS of the rest
        if (X.charAt(0) == Y.charAt(0)) {
            return 1 + LCS(X.substr(1), Y.substr(1));

        return Math.max(LCS(X.substr(1), Y), LCS(X, Y.substr(1)));
        }
    }

}
