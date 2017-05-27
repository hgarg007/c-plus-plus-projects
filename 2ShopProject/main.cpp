


int main() {
	Shop myshop;
	myshop.addItem(101, "Bat", 100);
	myshop.addItem(102, "Ball", 20);
	
	vector<int> itemList= {101, 102};
	vector<int> itemQuantity= {5, 10};
	myshop.addOrder(1001, "05-Mar-2015", itemList, itemQuantity);
	
	cout<<myshop.generateBill(1001);

}