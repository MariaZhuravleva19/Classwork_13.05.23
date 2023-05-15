#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream input;
    input.open("425(input).txt");
    fstream output;
    output.open("425(output).txt");

    int N, W, E;
    input >> N >> W >> E;

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x1 = 100 * i;
            int y1 = 100 * j;
            int x2 = x1 - 100;
            int y2 = y1 - 100;

            int det1 = (x1 - x2) * (W - y2) - (y1 - y2) * (0 - x2);
            int det2 = (x1 - x2) * (E - y2) - (y1 - y2) * (100 * N - x2);
            int det3 = (100 * N - 0) * (y1 - W) - (E - W) * (x1 - 0);
            int det4 = (100 * N - 0) * (y2 - E) - (W - E) * (x2 - 0);

            if ((det1 * det2 <= 0) && (det3 * det4 <= 0))
            {
                count++;
            }
        }
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}