namespace SALES
{
    const int QUARTERS=4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales & s, const double ar[], int n);/* kopiuje najmniejszy z czterech lub n elementów z tablicy ar
    do składowej sales struktury s i oblicza oraz zachowuje w odpowiednich składowych struktury sales wartości: średnią,
    minimalną i maksymalną; zeruje pozostałe elementy sales (jeśli są)*/
    void setSales(Sales & s);/* pobiera interaktywnie informacje dla 4 kwartałów, zachowuje je w składowej sales struktury s
    i oblicza oraz zachowuje średnią, minimalną i maksymalną*/
    void showSales(const Sales & s);//wyświetla strukturę
}
