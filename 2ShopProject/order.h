class Order {
	int orderNo;
	string orderDate;
	vector<OrderItem> orderItems;
public:
	Order();
	Order(int, string);
	void addOrderItem(Item, int);
	double findTotalPrice();
};