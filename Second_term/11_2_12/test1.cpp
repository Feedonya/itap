class Program
    {
        static void Sort(int[] a)
        {
            for (int i = 0; i < a.Length - 1; i++)
                for (int j = i; j < a.Length; j++)
                    if (a[i] > a[j])
                    {
                        int x = a[i];
                        a[i] = a[j];
                        a[j] = x;
                    }
        }
        static void output(int[,] a)
        {
            for (int i = 0; i < a.GetLength(0); i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                    Console.Write(a[i, j] + "\t");
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int[,] matrix = new int[6, 6];
            int[] abc = new int[6];
            int[] cba = new int[6];
            for (int i = 0; i < matrix.GetLength(0); i++)
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = rnd.Next(-30, 80);
                    if (i == j) abc[i] = matrix[i, j];
                    if (i == (matrix.GetLength(0)-1 - j)) cba[i] = matrix[i, j];
                }
            output(matrix);
            Sort(abc); Sort(cba);
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                {
                    if (i == j) matrix[i, j] = abc[i];
                    if (i == (matrix.GetLength(0)-1 - j)) matrix[i, j] = cba[i];
                }
            output(matrix);
            Console.ReadLine();
        }
    }