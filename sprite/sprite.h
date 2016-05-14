#define SPRITE_H 
#define SPRITE_DEF_FR 100 // default frame rate for new sprites, in waveform_table_t /second

/*
    class sprite_t
        "animated" sound objects
        */
        
        
class waveform_t;
//

enum action_type_t
{
    ACTION_LOAD,
    ACTION_HOLD,
    ACTION_MORPH,
    //ACTION_INVERT,
    ACTIONS
}; // action_type_t

// Action unit
typedef struct {
    unsigned short type;
	action_type_t   action;
  	   waveform_t*  waveform;
	  timepoint_t   length;
	  amplitude_t   amplitude;
} action_t;

// an audio frame



class sprite_t
{
    public:
        sprite_t ();
        
  	    // void MoveWavepoint   (const location_t wvpnt_location, const amplitude_t initial, const amplitude_t final, const timepoint_t time)    
  	    
        // amplitude_t GetAmplitudeAtlocation (const location_t wvpnt_location) const;       
        void MorphTo  (waveform_t* final, timepoint_t length);
        void Load     (waveform_t* final);    
        void Hold     (const timepoint_t);         
        void DoAction (action_t&);
        
        // Accessors for framerate
        void SetFrameRate (const double);
        double FrameRate () const;
        
        vector <waveform_table_t> Render (const double); 
        // Note: Render (const timepoint_t length)  is only available for sound_t objects
        // which are the equivalent of 'infinite' sprites
        
        // Generate frame at specific timepoint
        waveform_table_t GetFrame (const timepoint_t&);
                
        sprite_t (const string& sprite_name);
        string Name() const; // accessor for name
        
    private:  
        vector <waveform_table_t> frames;
        timepoint_t time;
		list <waveform_t> waveforms;        
        list <unsigned int> waveform_time;
        
        list <action_t> actions;
        
        double framerate;  
        
        string name;
}; /* sprite_t */

sprite_t* GetSprite (const string& identifier);


