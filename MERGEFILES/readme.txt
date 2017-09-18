### MERGE FILES

Classes - 
	Producer : 	used to produce data line by line from input file and place in buffer
				fileName & Buffer are members
				fileName : from which data is to be copied.
				Buffer : shared object between producer and consumer
				
	Consumer :	used to consume data line by line from buffer and place in output file
				fileName & Buffer are members
				fileName : single output file name(common for all consumers).
				Buffer : shared object between producer and consumer
				
	Buffer   :  buffer between producer and consumer.
				Producer & Consumer can do their task concurrently, Buffer methods(put & get) are synchronized over each other.
				data(actual buffer) and available(to synchronize put & get) are memeber varables.
				mutex & condition variables from thread libraries.
	
main -
	Process ->
	1 - enter output file name with complete path.
	2 - system will ask for input files
	3 - if user want to proceed then press 'y' otherwise 'n'
	4 - enter file name
		-> if wrong file name then go back to 2
	5 - merging starts.
	6- go back to 2
	7 - all input files removed.
	
	Summary ->
	For each input file, 3 objects (producer, consumer, buffer) are created, both producer & consumer are sharing same buffer object between them.
	
			  p_thread			 c_thread
				|					 |
	INPUT -> Producer -> Buffer ->Consumer -> OUTPUT
			|______________________________|
							|                   
						Synchronized
	
	Producer initialized with each input file and Consumer with same output file.
	
	For each input file 2 threads are created (one for putting data into buffer and second for getting data from buffer);
	Buffer methods are synchronized over a mutex variable to move both threads in alternate sequence.
	In Buffer, queue is used as buffer if its size==0 then get method has to wait.
	and in put a limit of size 10 has to be set for queue, it hast wait if queue size becomes 10;
	Threads are joined to main so they will have to complete before main thread.
	
	Exceptions:
		File not found exception has been handeled using try-catch mechanism.

------Thanks For Reading------
	