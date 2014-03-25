/* У меня нет компилятора Java, за работоспособность кода не отвечаю D: */

public class BST{

   private Node root;

   private class Node{
       private int key;
       private Node left, right;

       public Node(int key){
	  this.key = key;
       }
   }

   public void put(int key){
       put(root, key);
   }

   private void put(Node x, int key){
       if(x == null ) x = new Node(key);
       
       if(key < x.key)
	  put(x.left, key);
       else if(key > x.key)
	  put(x.right, key);
   }  
   
   public boolean find(int key){
       return find(root, key);
   }

   private boolean find(Node x,int key) {
        if(x == null) return false;
       
        if(key < x.key)
	  return find(x.left, key);
        else if(key > x.key)
	  return find(x.right, key);
	else return true;
   } 

   public void delete(int key){
      delete(root,key);
   }

   private void delete(Node x,int key){
     
      if(key < x.key)
	  delete(x.left, key);
      else if(key > x.key)
	  delete(x.right, key);
      else {
          if(x.right == null) {
	      x = x.left;
          }
          else if(x.left == null) {
	      x = x.right;
          }
          
          Node min = x.right;
          
          while(min.left != null )
	    min = min.left;
	  
	  x.key = min.key;
	  min = min.right;
	
      }	  
    }
    
    public void show(Node x){
	if (x.left != null) show(x.left);
	System.out.print(x.key + " ");
	if (x.right != null) show(x.right);
    }
} 
