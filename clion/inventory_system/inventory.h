
#ifndef INVENTORY_SYSTEM_INVENTORY_H
#define INVENTORY_SYSTEM_INVENTORY_H
class Inventory{
public:
    Inventory();
    ~Inventory();
    void welcome_message() const;
    void print_production_status_first_line() const;
    char prompt_good_or_bad() const;
    int promt_number_sell() const;
    char prompt_continue() const;
    void update_private_variables(char good_bad, int sale_number);
    void run_inventory();
    void print_status_lastline() const;
private:
    int month=0;
    int widget_onhand=0;
    int widget_back_ordered=0;
};
#endif //INVENTORY_SYSTEM_INVENTORY_H
