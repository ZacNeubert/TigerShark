package main
import java.io._
import java.lang.Math
import java.util.ArrayList

object mandelbrot {
val imageHeight = 512;
val imageWidth = 512;
val maxN = 256;
val minR = -1.5;
val maxI = 1.0;
val maxR = 0.5;
val minI = -1.0;
val SERIAL_AVERAGE = 2.151;
var timesRan = 0;
var time = Long.MaxValue;

class Color(val red:Integer, val green:Integer, val blue: Integer) 
{
	var this.red = red;
	var this.green = green;
	var this.blue = blue;
	
};

var ColorList = new ArrayList[Color];

def mapToReal(x:Integer, imageWidth:Integer, minR:Double, maxR:Double):Double= {
	var range = maxR - minR;
	x * (range / imageWidth) + minR;
}

def mapToImaginary(y:Integer, imageHeight:Integer, minI:Double, maxI:Double):Double= {
	var range = maxI - minI;
	y * (range / imageHeight) + minI;
}

def findMandelbrot(cr:Double, ci:Double, max_iterations:Integer):Integer= {
	var i = 0;
	var zr = 0.0;
	var zi = 0.0;
	while (i < max_iterations && zr *zr + zi * zi < 4.00) {
		var temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i = i + 1;
	}
	return i;
}

def writeMandelbrotRegular() {
	val out = new FileOutputStream("output_image.ppm");
	out.write("P3\n".getBytes());
	out.write((imageWidth + " " + imageHeight + "\n").getBytes());
	out.write((maxN + "\n").getBytes());
	var i = 0;
	for(i <- 0 until imageHeight){
	  var j= 0;
	  for(j <- 0 until imageWidth){
	    var cr = mapToReal(i, imageWidth, minR, maxR);
			var ci = mapToImaginary(j, imageHeight, minI, maxI);

			var n = findMandelbrot(cr, ci, maxN);

			var r = n * n % 256;
			var g = n * n % 256;
			var b = n * n % 256;

			out.write((r + " " + g + " " + b + " ").getBytes());
	  }
	  out.write("\n".getBytes());
	}
	
	out.flush();
	out.close();
}

def timeFunction() {
	var start = System.currentTimeMillis();

	writeMandelbrotRegular();

	var end = System.currentTimeMillis();
	var tempTime = end - start;
	timesRan += 1;
	time = tempTime;
}

def main(args: Array[String]){

	timeFunction();

	System.out.println("Finished! Time taken: " + time + " milliseconds");
	
}

}