/**
 * Created by jackson on 19.04.14.
 */

import java.io.IOException;
import java.util.logging.*;

public class LimitedStack {

        private static Logger log = Logger.getLogger(LimitedStack.class.getName());

        public static void  main(String[] args){
            try {
                LogManager.getLogManager().readConfiguration(
                        LimitedStack.class.getResourceAsStream("./logging.properties"));
            } catch (IOException e) {
                System.err.println("Could not setup logger configuration: " + e.toString());
            }

            try {
                LimitedStack stack = new LimitedStack(3);
                stack.push("Hello ");
                stack.push(3.1415);
                stack.pop();
                stack.push("world!\n");
                stack.push("I want to destroy your stack!\n");

                Object o = stack.top();

                stack.push("I have destroyed your stack!");
            } catch(StackException e)
            {
                log.log(Level.SEVERE, "We have catched exception here: ", e);
            }

            try {
                LimitedStack stack2 = new LimitedStack(-1);
            } catch (AssertionError ae) {
               log.log(Level.SEVERE, "We have catched AssertionError;", ae);
            }
        }

        public LimitedStack(int capacity) {
            log.entering(LimitedStack.class.getName(), "LimitedStack(int capacity)", capacity);

            assert capacity > 0 : "Invalid capacity value";
            log.finest("assert capacity > 0 is validated");


            this.capacity = capacity;
            size = 0;
            top = null;

            log.exiting(LimitedStack.class.getName(), "LimitedStack(int capacity)");
        }

        public boolean isEmpty() {
            log.entering(LimitedStack.class.getName(), "isEmpty()");
            log.exiting(LimitedStack.class.getName(), "isEmpty()", top == null);

            return top == null;
        }

        public boolean isFull() {
            log.entering(LimitedStack.class.getName(), "isFull()");
            log.exiting(LimitedStack.class.getName(), "isFull()", size == capacity);

            return size == capacity;
        }

        public void clear() {
            log.entering(LimitedStack.class.getName(), "clear()");

            top = null;
            size = 0;

            log.exiting(LimitedStack.class.getName(), "clear()");
        }

        public void push(Object x) throws StackException {
            log.entering(LimitedStack.class.getName(), "push(Object x)", x);

            if(capacity == size)
                throw new StackException("LimitedStack.push(): Stack overflow!\n");

            top = new Node(x, top);
            size++;

            log.exiting(LimitedStack.class.getName(), "push(Object x)");
        }

        public void pop() throws StackException {
            log.entering(LimitedStack.class.getName(), "pop()");

            if(isEmpty()){
                StackException e = new StackException("LimitedStack.top(): Exctracting from empty stack!\n");

                log.throwing(LimitedStack.class.getName(), "exceptionDriver", e);

                throw e;
            }
            top = top.next;
            size--;

            log.exiting(LimitedStack.class.getName(), "pop()");
        }

        public Object top() throws StackException {
            log.entering(LimitedStack.class.getName(), "top()");

            if(isEmpty()) {
                StackException e = new StackException("LimitedStack.top(): Reading from empty stack!\n");

                log.throwing(LimitedStack.class.getName(), "exceptionDriver", e);

                throw e;
            }
            log.exiting(LimitedStack.class.getName(), "top()", top);
            return top.element;
        }

        public int getCapacity(){
            return capacity;
        }

        public int getSize(){
            return size;
        }

        private Node top;
        private int capacity;
        private int size;

        class Node {
            public Node( Object newElement, Node newNext ) {
                element = newElement;
                next = newNext;
            }

            public Object element;
            public Node next;
        }
}

class StackException extends Exception
{
    StackException(String message)
    {
        super(message);
    }
}
