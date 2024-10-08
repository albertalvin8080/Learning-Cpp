#include <iostream>

#define ITEM_QUANTITY 3
#define COL 4
#define ROW 4

using string = std::string;

class Item
{
public:
    const string name;
    const int pounds;
    const int price;

    Item(const string &name, const int &pounds, const int &price) : name(name), pounds(pounds), price(price) {}
};

int main()
{
    Item items[ROW] = {
        Item("STEREO", 4, 3000),
        Item("LAPTOP", 3, 2000),
        Item("GUITAR", 1, 1500),
        Item("TV", 1, 2000),
    };

    int pounds[COL];
    for (int i = 0; i < COL; ++i)
        pounds[i] = i + 1;
    int grid[ROW][COL] = {-1};

    for (int i = 0; i < ROW; ++i)
    {
        const Item &c_item = items[i];
        for (int j = 0; j < COL; ++j)
        {
            const int &remaning_pounds = pounds[j] - c_item.pounds;
            if (i == 0)
            {
                if (remaning_pounds < 0)
                    grid[i][j] = 0;
                else
                    grid[i][j] = c_item.price;
                continue;
            }

            if (remaning_pounds < 0)
            {
                grid[i][j] = grid[i - 1][j];
            }
            else if (remaning_pounds == 0)
            {
                grid[i][j] = std::max<int>(c_item.price, grid[i - 1][j]);
            }
            else
            {
                grid[i][j] = std::max<int>(c_item.price + grid[i - 1][j - c_item.pounds], grid[i - 1][j]);
            }
        }
    }

    std::cout << "Highest value sack we can carry: " << grid[ROW - 1][COL - 1] << std::endl;

    return 0;
}