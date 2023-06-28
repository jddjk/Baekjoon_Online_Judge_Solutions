using System;
using System.Linq;

class MainClass {
    static bool[] brokenButtons = new bool[10];

    public static void Main(string[] args) {
        int targetChannel = int.Parse(Console.ReadLine());
        int brokenCount = int.Parse(Console.ReadLine());

        if (brokenCount > 0) {
            int[] broken = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int i = 0; i < brokenCount; i++) {
                brokenButtons[broken[i]] = true;
            }
        }

        int minPress = Math.Abs(targetChannel - 100);

        for (int i = 0; i <= 1000000; i++) {
            int channel = i;
            int length = CheckChannel(i);

            if (length > 0) {
                int press = Math.Abs(channel - targetChannel);
                if (minPress > length + press)
                    minPress = length + press;
            }
        }

        Console.WriteLine(minPress);
    }

    static int CheckChannel(int channel) {
        if (channel == 0) {
            if (brokenButtons[0])
                return 0;
            else
                return 1;
        }

        int length = 0;

        while (channel > 0) {
            if (brokenButtons[channel % 10]) {
                return 0;
            }
            length++;
            channel /= 10;
        }
        return length;
    }
}
