/* 
 * Recursively list directories/files through Java, akin to Linux's `ls -R` command.
 * (c) 2017, KazWolfe. Under MIT license.
 *
 * To use, save to `Recurse.java` and compile with `javac Recurse.java`.
 * Run with `java -cp . Recurse /path/to/operate/on`. Be sure you are passing in a folder.
 */

import java.io.File;
import java.lang.String;

class Recurse {
    public static void main(String[] args) {
        // Call the recursive method.
        recursivelyList(new File(args[0]));
    }

    public static void recursivelyList(File folder) {
        File[] fileList = folder.listFiles();
        String[] fileNames = new String[fileList.length];

        // Get pretty names for printing.
        for (int i = 0; i < fileList.length; i++) {
            fileNames[i] = fileList[i].getName();
        }

        System.out.println(folder.getPath() + ":\n" + String.join(" ", fileNames));
        
        // Iterate through and call this function for any sub-directories.
        for (File f2 : fileList) {
            if (f2.isDirectory()) {
                System.out.println("");
                recursivelyList(f2);
            }
        }
    }
}