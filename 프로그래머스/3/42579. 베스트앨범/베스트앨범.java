import java.util.*;
import java.util.stream.*;

class Solution {
    
    public static class Genre {
        String name; int total;
        
        public Genre(String name, int total) {
            this.name = name; this.total = total;
        }
    }
    
    public static class Music {
        int plays; int idx;
        
        public Music(int plays, int idx) {
            this.plays = plays; this.idx = idx;
        }
    }
    public int[] solution(String[] genres, int[] plays) {
        
        Map<String, Integer> genreCnt = new HashMap<>();
        Map<String, List<Music>> genreMusics = new HashMap<>();
        
        for (int i = 0; i < genres.length; ++i) {
            String genre = genres[i];
            
            if (!genreCnt.containsKey(genre)) {
                genreCnt.put(genre, 0);
                genreMusics.put(genre, new ArrayList());
            }
            
            genreCnt.put(genre, genreCnt.get(genre) + plays[i]);
            genreMusics.get(genre).add(new Music(plays[i], i));
        }
        
        for (String key : genreMusics.keySet()) {
            genreMusics.get(key).sort(new Comparator<Music>() {
                @Override
                public int compare(Music m1, Music m2) {
                    if (m1.plays < m2.plays) return 1;
                    else if (m1.plays > m2.plays) return -1;
                    if (m1.idx > m2.idx) return 1;
                    else if (m1.idx < m2.idx) return -1;
                    return 0;
                }
            });
        }
        
        List<Genre> genre = genreCnt.keySet().stream()
            .map(g -> new Genre(g, genreCnt.get(g)))
            .collect(Collectors.toList());
        Collections.sort(genre, new Comparator<Genre>() {
                @Override
                public int compare(Genre g1, Genre g2) {
                    if (g1.total < g2.total) return 1;
                    else if (g1.total > g2.total) return -1;
                    return 0;
                }
            });
        
        List<Integer> answer = new ArrayList();
        
        for (Genre g : genre) {
            String name = g.name;
            
            List<Integer> ggs = genreMusics.get(name).stream()
                .map(m -> m.idx)
                .collect(Collectors.toList());
            if (ggs.size() > 0) answer.add(ggs.get(0));
            if (ggs.size() > 1) answer.add(ggs.get(1));
        }
        
        int[] realAnswer = new int[answer.size()];
        
        for (int i = 0; i < answer.size(); ++i) {
            realAnswer[i] = answer.get(i);
        }
        
        return realAnswer;
    }
}