class Shop {
	vector<Item> items;
	vector<Order> orders;
	
	public:
	
	Shop();
	void addItem(int, string, float);
	void addOrder(int, string, vector<int>, vector<int>);
	int generateBill(int );
};