#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool sortPrice(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(Review & rr);
std::shared_ptr<Review> makesp(Review r);
void ShowReview(const std::shared_ptr<Review> rr);
void menu();
int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
    {
        books.push_back(makesp(temp));
    }
    vector<shared_ptr<Review>> books2=books;
    int choice;
    if (books.size() > 0)
    {
        cout << "Dziękuję. Podałeś "
            << books.size() << " książek\n";
        menu();
        while (cin>>choice&&choice!=0)
        {
            switch (choice)
            {
                case 1 : cout<<"\nW kolejności wprowadzenia:\nOcena\tKsiązka\tCena\n";
                         for_each(books.begin(), books.end(), ShowReview);
                         break;
                case 2 : sort(books2.begin(), books2.end());
                         cout<<"\nW kolejności alfabetycznej:\nOcena\tKsiązka\tCena\n";
                         for_each(books2.begin(), books2.end(), ShowReview);
                         break;
                case 3 : sort(books2.begin(), books2.end(), worseThan);
                         cout<<"\nWedług ocen rosnąco:\nOcena\tKsiązka\tCena\n";
                         for_each(books2.begin(), books2.end(), ShowReview);
                         break;
                case 4 : sort(books2.begin(), books2.end(), worseThan);
                         cout<<"\nWedług ocen malejąco:\nOcena\tKsiązka\tCena\n";
                         for_each(books2.rbegin(), books2.rend(), ShowReview);
                         break;
                case 5 : sort(books2.begin(), books2.end(), sortPrice);
                         cout<<"\nWedług cen rosnąco:\nOcena\tKsiązka\tCena\n";
                         for_each(books2.begin(), books2.end(), ShowReview);
                         break;
                case 6 : sort(books2.begin(), books2.end(), sortPrice);
                         cout<<"\nWedług cen malejąco:\nOcena\tKsiązka\tCena\n";
                         for_each(books2.rbegin(), books2.rend(), ShowReview);
                         break;
                default : cout<<"\nBłędny wybór! Spróbuj jeszcze raz!\n";
                          break;
            }
            while (cin.get()!='\n')
                continue;
            menu();
        }
    }
    else
        cout << "Brak danych. ";
    cout << "Koniec.\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}
bool sortPrice(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1 -> price < r2 -> price)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << " Wpisz tytuł książki (koniec, aby zakończyć): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "koniec")
        return false;
    std::cout << "Wpisz ocenę: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // pozbycie się reszty danych wejściowych
    while (std::cin.get() != '\n')
        continue;
    std::cout<<"Wpisz cenę: ";
    std::cin>>rr.price;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

std::shared_ptr<Review> makesp(Review r)
{
    return std::shared_ptr<Review>(new Review(r));
}

void menu()
{
    using std::cout;
    cout<<"\nWybierz kolejność wyświetlania:\n";
    cout<<" 1. w kolejności wprowadzenia;\n 2. w kolejności alfabetycznej;\n";
    cout<<" 3. wg ocen rosnąco;\n 4. wg ocen malejąco;\n";
    cout<<" 5. wg cen rosnąco;\n 6. wg cen malejąco;\n 0. koniec;\n";
    cout<<"Twój wybor: ";
}
