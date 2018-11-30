# cpp.poolgame.stage1


 Object Oriented Design Patterns 
Assign 1 
Kashif Akram – 460458380 
Design patterns used in assignment: 
1. Abstract Factory 

Application in the project: 
I used (GameAbstractFactory) abstract factory to provide abstract methods to create game objects, Table and Balls, FirstStageFactory is concrete abstract factory which provides the concrete implementation to client to create objects and hides the decouples the client implementation. 
Advantages: 
•	• This design pattern helps to create different relevant products without their concrete classes. We will create concrete factory class for client and this will help to decouple the actual class from the object instance of class. For example if there will be needing to change products then client code will not be modified, we just modify the concrete factory classes or abstract factory signature if required, client code will remain same. 
•	• Abstract factory provides the ability to have several implementations for different purposes for the actual objects which will implement the same interface and won’t know about the concrete factory implementations. 

Disadvantages: 
•	• Abstract factory in enterprise level software could be big pain if there’s requirement later after project completion to add new concrete classes to abstract factory for client usage. 

2. Builder 

