/* Generated By:JJTree: Do not edit this line. ASTarray.java Version 4.1 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY= */
package com.eprosima.ddscs.idl.ast;

import com.eprosima.ddscs.idl.*;

//@SuppressWarnings("all")
public class ASTarray extends SimpleNode {
  public ASTarray(int id) {
    super(id);
  }

  public ASTarray(IDLParser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(IDLParserVisitor visitor, Object data) {
    return visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=c662382aab1fcfc82e01856e77c013c2 (do not edit this line) */