class Solution {
    public String simplifyPath(String path) {
        Queue<String> dirs = new LinkedList<>();
        Stack<String> paths = new Stack<>();
        String simplified = "";
        String dir = "";
        for(int i=0; i<path.length(); i++) {
            if(path.charAt(i) == '/') {
                if(dir.length() > 0) {
                    dirs.add(new String(dir));
                }
                dir = "";
                continue;
            }
            
            dir = dir + String.valueOf(path.charAt(i));
        }
        
        if(dir.length() > 0) {
            dirs.add(dir);
        }
        
        while(!dirs.isEmpty()) {
            dir = dirs.remove();
            if(dir.equals(".")) {
                continue;
            }else if(dir.equals("..")) {
                if(!paths.empty()) {
                    paths.pop();
                }
            }else {
                paths.push(dir);
            }
        }
        
        while(!paths.empty()) {
            dir = paths.pop();
            if(dir.equals(".")) {
                continue;
            }else if(dir.equals("..")) {
                if(!paths.empty())
                    paths.pop();
                continue;
            }
            if(simplified.equals("")) {
                simplified = dir;
            }
            else {
                simplified = dir + "/" + simplified;
            }
        }
        
        simplified = "/"+simplified;
        
        return simplified;
        
    }
}
