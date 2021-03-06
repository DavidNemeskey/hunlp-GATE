package hu.nytud.gate.postaggers;

import java.net.URL;

import gate.FeatureMap;
import gate.creole.metadata.CreoleParameter;
import gate.creole.metadata.CreoleResource;
import gate.taggerframework.*;

/**
 * This class is inherited from taggerframework.GenericTagger.
 * We only override some CREOLE resource parameter default values
 * which are needed to run the hunpos command line binary correctly. 
 */
@CreoleResource(name = "HU [OLD] 3. POS Tagger (HunPos, KR?, GenericTagger) [Linux]", 
				comment = "Expects tokenized text. Outputs KR codes. Calls hunpos command line binary via TaggerFramework's GenericTagger",
				icon = "pos-tagger") 
public class HunPosCommandLine extends GenericTagger {

	private static final long serialVersionUID = 1L;
	
	@CreoleParameter(defaultValue = "ISO-8859-2") 
	public void setEncoding(String encoding) { 
	    super.setEncoding(encoding); 
	} 	
	
	@CreoleParameter(defaultValue = "false")
	public void setFailOnUnmappableCharacter(Boolean failOnUnmappableCharacter) {
		super.setFailOnUnmappableCharacter(failOnUnmappableCharacter);;
	}
	
	@CreoleParameter(defaultValue = "string=1;category=2")
	public void setFeatureMapping(FeatureMap featureMapping) {
		super.setFeatureMapping(featureMapping);
	}

	@CreoleParameter(defaultValue = "(.+)\t(.+)")
	public void setRegex(String regex) {
		super.setRegex(regex);
	}
	
	@CreoleParameter(defaultValue = "resources/hunpos/runhunpos.sh") 
	public void setTaggerBinary(URL url) { 
	    super.setTaggerBinary(url); 
	}
	
	@CreoleParameter(defaultValue = "resources/hunpos")
	public void setTaggerDir(URL taggerDir) {
		super.setTaggerDir(taggerDir);
	}
	
}
