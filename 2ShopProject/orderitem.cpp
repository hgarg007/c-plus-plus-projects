OrderItem:: OrderItem() {

}
OrderItem:: OrderItem(Item i, int qty) {
	this->i=i;
	this->quantity=qty;
}
int OrderItem:: getQuantity() {
	return quantity;
}
Item OrderItem:: getItem() {
	return i;
}