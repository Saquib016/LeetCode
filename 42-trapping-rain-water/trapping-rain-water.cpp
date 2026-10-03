class Solution {
public:
    int trap(vector<int>& height) {
        int lmax, rmax,total,n,i,j;
        lmax = rmax = total = 0;
        n=height.size(),i=0,j=n-1;
        while (i<j){
            if(height[i]<height[j]){  //Current(present element) left is smaller than current right so that the water will store in it and the left side need to be bigger which is next step. //another way to think--> but then we need to use lmax<rmax ====>> //left side is smaller then water can fill upto then only and right we know that bigger than left so water will hold into it.
                if(lmax>height[i]){ //we need to check left is bigger or not if bigger than the place we are talking about then water will hold there other wise we need to change our lmax.Just imagine and see the diagram.
                    total+= lmax - height[i];
                }
                else lmax = height[i]; //if height is greater then change left max cause left max meaning is that its maximum in left side
                i++;
            }
            else{
                if(rmax>height[j]){ //same logic just from right side.
                    total += rmax - height[j];
                }
                else{
                    rmax = height[j]; // Same Logic Here.
                }
                j--;
            }
        }
        return total;
    }
};