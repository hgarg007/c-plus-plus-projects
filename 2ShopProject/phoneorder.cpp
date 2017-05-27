PhoneOrder:: PhoneOrder() {

}

PhoneOrder:: PhoneOrder(string phone) {
	this->callbackNumber= phone;
}	

string PhoneOrder:: getCallBackNumber() {
	return callBackNumber;
}