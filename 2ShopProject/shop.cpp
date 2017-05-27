

void Shop:: addItem(int id, string name, float price) {
	Item i(id, name, price);
	items.push_back(i);
}

void Shop:: addOrder(int oid, string date, vector<int> itemList, vector<int> itemQuantity) {

	Order o(oid, date);
	for(int i=0; i<items.size(); i++) {
		for(int j=0; j< itemList.size(); j++) {
			if(items[i].getItemId()==itemList[j]) {
				o.addOrderItem(items[i], itemQuantity[j]);
				break;
			}
		}
	}
	orders.push_back(o);
}

int Shop:: generateBill(int oid) {
	for(int i=0; i<orders.size(); i++) {
		if(oid== orders[i].getOrderNo()) {
			return orders[i].findTotalPrice();
		}
	}
}