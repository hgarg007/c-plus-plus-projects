

Order::Order() {

}

Order::Order(int oid, string date) {
	this->orderNo= oid;
	this->oredrDate= date;
}

void Order::addOrderItem(Item i, int qty) {
	OrderItem oi(i, qty);
	orderItems.push_back(oi);
}

double Order:: findTotalPrice() {
int tprice=0;
for(int i=0; i<orderItems.size(); i++) {
	tprice+= orderItems[i].getItem().getItemPrice() *  orderItems[i].getQuantity();
}
return tprice;
}
