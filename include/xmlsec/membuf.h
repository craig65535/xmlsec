/** 
 * XMLSec library
 *
 * Memory buffer transform
 *
 * See Copyright for the status of this software.
 * 
 * Author: Aleksey Sanin <aleksey@aleksey.com>
 */
#ifndef __XMLSEC_MEMBUF_H__
#define __XMLSEC_MEMBUF_H__    

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <libxml/tree.h>

#include <xmlsec/xmlsec.h>
typedef struct _xmlSecBuffer				xmlSecBuffer, *xmlSecBufferPtr;

enum xmlSecAllocMode{
    xmlSecAllocExact = 0,
    xmlSecAllocDouble
};

/*****************************************************************************
 *
 * xmlSecBuffer
 *
 ****************************************************************************/
struct _xmlSecBuffer {
    unsigned char* 	 data;
    size_t 		 size;
    size_t		 maxSize;
    enum xmlSecAllocMode allocMode;
};

XMLSEC_EXPORT xmlSecBufferPtr	xmlSecBufferCreate		(size_t size);
XMLSEC_EXPORT void		xmlSecBufferDestroy		(xmlSecBufferPtr buf);
XMLSEC_EXPORT int		xmlSecBufferInitialize		(xmlSecBufferPtr buf,
								 size_t size);
XMLSEC_EXPORT void		xmlSecBufferFinalize		(xmlSecBufferPtr buf);
XMLSEC_EXPORT unsigned char*	xmlSecBufferGetData		(xmlSecBufferPtr buf);
XMLSEC_EXPORT int		xmlSecBufferSetData		(xmlSecBufferPtr buf,
								 const unsigned char* data,
								 size_t size);
XMLSEC_EXPORT size_t		xmlSecBufferGetSize		(xmlSecBufferPtr buf);
XMLSEC_EXPORT int		xmlSecBufferSetSize		(xmlSecBufferPtr buf,
								 size_t size);
XMLSEC_EXPORT size_t		xmlSecBufferGetMaxSize		(xmlSecBufferPtr buf);
XMLSEC_EXPORT int		xmlSecBufferSetMaxSize		(xmlSecBufferPtr buf,
								 size_t size);
XMLSEC_EXPORT void		xmlSecBufferEmpty		(xmlSecBufferPtr buf);
XMLSEC_EXPORT int		xmlSecBufferAppend		(xmlSecBufferPtr buf,
								 const unsigned char* data,
								 size_t size);
XMLSEC_EXPORT int		xmlSecBufferPrepend		(xmlSecBufferPtr buf,
								 const unsigned char* data,
								 size_t size);
XMLSEC_EXPORT int		xmlSecBufferRemoveHead		(xmlSecBufferPtr buf,
								 size_t size);
XMLSEC_EXPORT int		xmlSecBufferRemoveTail		(xmlSecBufferPtr buf,
								 size_t size);

XMLSEC_EXPORT int		xmlSecBufferBase64NodeContentRead(xmlSecBufferPtr buf,
								 xmlNodePtr node);
XMLSEC_EXPORT int		xmlSecBufferBase64NodeContentWrite(xmlSecBufferPtr buf,
								 xmlNodePtr node,
								 int columns);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_MEMBUF_H__ */

