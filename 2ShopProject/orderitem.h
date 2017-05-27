class OrderItem {
	Item i;
	int quantity;
	
public:

	OrderItem();
	OrderItem(Item, int);
	int getQuantity();
	Item getItem();
};