Item:: Item() {
}
Item::Item(int id, string name, float price) {
	this->itemId= id;
	this->itemName= name;
	this->itemPrice= price;
	
}
string Item::getItemName() {
	return itemName;
}
int Item::getItemId() {
	return itemId;
}
float Item::getItemPrice() {
	return itemPrice;
}