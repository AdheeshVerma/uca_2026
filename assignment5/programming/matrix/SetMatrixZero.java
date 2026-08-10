public class SetMatrixZero {
    public static void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        boolean firstRow = false;
        boolean firstCol = false;
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0)
                firstRow = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRow) {
            for (int j = 0; j < m; j++) {
                if (matrix[0][j] == 0) {
                    matrix[0][j] = 0;
                }
            }
        }
        if (firstCol) {
            for (int j = 0; j < m; j++) {
                if (matrix[0][j] == 0) {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                { 1, 1, 1 },
                { 1, 0, 1 },
                { 1, 1, 1 }
        };

        System.out.println("Before:");
        printMatrix(matrix);

        setZeroes(matrix);

        System.out.println("\nAfter:");
        printMatrix(matrix);

    }
}
